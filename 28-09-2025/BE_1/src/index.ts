import type { RowDataPacket, ResultSetHeader } from 'mysql2';

import express, { Request, Response } from 'express';
import cors from 'cors';
import bcrypt from 'bcrypt';
import dotenv from 'dotenv';
import pool from './database';

dotenv.config();

const app = express();
const PORT = process.env.PORT || 5000;

// Middleware
app.use(cors({
  origin: ['http://localhost:5173', 'http://localhost:3000'],
  credentials: true
}));
app.use(express.json());

// Types
interface UserRegistration {
  username: string;
  email: string;
  password: string;
}

interface User {
  id: number;
  username: string;
  email: string;
  password: string;
  created_at: Date;
  updated_at: Date;
}

// Test database connection
const testConnection = async () => {
  try {
    const connection = await pool.getConnection();
    console.log('🟢 Connected to MySQL Database!');
    connection.release();
  } catch (error) {
    console.error('❌ MySQL connection failed:', error);
  }
};

testConnection();

// Routes
app.get('/', (req: Request, res: Response) => {
  res.json({
    message: '🎉 MySQL User Registration API is running!',
    database: 'Connected to MySQL',
    endpoints: {
      register: 'POST /api/register',
      users: 'GET /api/users',
      user: 'GET /api/users/:id'
    }
  });
});

// User Registration Route
app.post('/api/register', async (req: Request<{}, {}, UserRegistration>, res: Response) => {
  const connection = await pool.getConnection();
  
  try {
    const { username, email, password } = req.body;

    // Validation
    if (!username || !email || !password) {
      return res.status(400).json({
        message: 'सभी fields भरना जरूरी है!',
        status: 'error'
      });
    }

    if (password.length < 6) {
      return res.status(400).json({
        message: 'Password कम से कम 6 characters होना चाहिए!',
        status: 'error'
      });
    }

    // Check if user already exists
    const [existingUsers] = await connection.execute<RowDataPacket[]>(
      'SELECT id FROM users WHERE email = ? OR username = ?',
      [email, username]
    );

    if (existingUsers.length > 0) {
      return res.status(400).json({
        message: 'User already exists with this email or username!',
        status: 'error'
      });
    }

    // Hash password
    const saltRounds = 10;
    const hashedPassword = await bcrypt.hash(password, saltRounds);

    // Insert new user into database
    const [result] = await connection.execute<ResultSetHeader>(
      'INSERT INTO users (username, email, password) VALUES (?, ?, ?)',
      [username, email, hashedPassword]
    );

    // Get the created user
    const [newUser] = await connection.execute<RowDataPacket[]>(
      'SELECT id, username, email, created_at FROM users WHERE id = ?',
      [result.insertId]
    );

    console.log('✅ New user registered in MySQL:', { username, email, id: result.insertId });

    res.status(201).json({
      message: `🎉 Welcome ${username}! Registration successful!`,
      status: 'success',
      user: newUser[0]
    });

  } catch (error: any) {
    console.error('❌ Registration error:', error);
    
    if (error.code === 'ER_DUP_ENTRY') {
      res.status(400).json({
        message: 'Username or email already exists!',
        status: 'error'
      });
    } else {
      res.status(500).json({
        message: 'Server error during registration',
        status: 'error'
      });
    }
  } finally {
    connection.release();
  }
});

// Get all users
app.get('/api/users', async (req: Request, res: Response) => {
  const connection = await pool.getConnection();
  
  try {
    const [users] = await connection.execute<RowDataPacket[]>(
      'SELECT id, username, email, created_at FROM users ORDER BY created_at DESC'
    );
    
    res.json({
      message: '📋 All registered users from MySQL',
      count: users.length,
      users: users
    });
  } catch (error) {
    console.error('❌ Error fetching users:', error);
    res.status(500).json({ 
      message: 'Error fetching users',
      status: 'error'
    });
  } finally {
    connection.release();
  }
});

// Get single user by ID
app.get('/api/users/:id', async (req: Request, res: Response) => {
  const connection = await pool.getConnection();
  
  try {
    const userId = req.params.id;
    
    const [users] = await connection.execute<RowDataPacket[]>(
      'SELECT id, username, email, created_at FROM users WHERE id = ?',
      [userId]
    );
    
    if (users.length === 0) {
      return res.status(404).json({
        message: 'User not found',
        status: 'error'
      });
    }
    
    res.json({
      message: '👤 User details',
      user: users[0]
    });
  } catch (error) {
    console.error('❌ Error fetching user:', error);
    res.status(500).json({ 
      message: 'Error fetching user',
      status: 'error'
    });
  } finally {
    connection.release();
  }
});

app.listen(PORT, () => {
  console.log(`🚀 Server running on http://localhost:${PORT}`);
  console.log(`🗄️ MySQL database connected!`);
  console.log(`🔐 User registration system ready!`);
});
