import express from 'express';
import cors from 'cors';

const app = express();
const PORT = 5000;

// Middleware (like teaching the robot to understand messages)
app.use(cors());
app.use(express.json());

// Our magical todo storage (in real life, this would be a database!)
interface Todo {
  id: string;
  text: string;
  completed: boolean;
  createdAt: Date;
}

let todos: Todo[] = [
  { id: '1', text: 'Learn TypeScript', completed: false, createdAt: new Date() },
  { id: '2', text: 'Build awesome apps', completed: false, createdAt: new Date() }
];

// Test route to make sure everything works
app.get('/api/test', (req, res) => {
  res.json({ success: true, message: 'Backend is working! 🎉' });
});

// Get all todos (like asking "What's on my list?")
app.get('/api/todos', (req, res) => {
  res.json({ success: true, todos });
});

// Add a new todo (like saying "Add this to my list!")
app.post('/api/todos', (req, res) => {
  const { text } = req.body;
  
  const newTodo: Todo = {
    id: Date.now().toString(), // Simple ID generator
    text,
    completed: false,
    createdAt: new Date()
  };
  
  todos.push(newTodo);
  res.json({ success: true, todo: newTodo });
});

// Toggle todo completion (like checking off a task!)
app.put('/api/todos/:id', (req, res) => {
  const { id } = req.params;
  const todo = todos.find(t => t.id === id);
  
  if (!todo) {
    return res.status(404).json({ success: false, message: 'Todo not found!' });
  }
  
  todo.completed = !todo.completed;
  res.json({ success: true, todo });
});

// Delete a todo (like erasing it from the list)
app.delete('/api/todos/:id', (req, res) => {
  const { id } = req.params;
  todos = todos.filter(t => t.id !== id);
  res.json({ success: true, message: 'Todo deleted!' });
});

app.listen(PORT, () => {
  console.log(`🚀 Todo Helper running on http://localhost:${PORT}`);
});
