import React, { useState, useEffect } from 'react';
import axios from 'axios';


//Types
interface Todo {
  id: string;
  text: string;
  completed: boolean;
  createdAt: string;
}

//State Variables
// useState: useState allows state to be managed within a component 
function App() {
  const [todos, setTodos] = useState<Todo[]>([]);
  const [newTodo, setNewTodo] = useState('');
  const [loading, setLoading] = useState(false);
  const [connected, setConnected] = useState(false);

  const API_URL = 'http://localhost:5000/api';

  // Test connection when app starts
  // useEffect: allows a component to connect with an external system such as an API fetching data
  useEffect(() => {
    testConnection();
    fetchTodos();
  }, []);

  const testConnection = async () => {
    try {
      const response = await axios.get(`${API_URL}/test`);
      if (response.data.success) {
        setConnected(true);
        console.log('🎉 Frontend connected to backend!', response.data);
      }
    } catch (error) {
      console.error('❌ Connection failed:', error);
      setConnected(false);
    }
  };

  const fetchTodos = async () => {
    try {
      setLoading(true);
      const response = await axios.get(`${API_URL}/todos`);
      setTodos(response.data.todos);
    } catch (error) {
      console.error('Failed to fetch todos:', error);
    } finally {
      setLoading(false);
    }
  };

  const addTodo = async () => {
    if (!newTodo.trim()) {
      alert('Please write something first!');
      return;
    }

    try {
      const response = await axios.post(`${API_URL}/todos`, { text: newTodo });
      setTodos([...todos, response.data.todo]);
      setNewTodo('');
    } catch (error) {
      console.error('Failed to add todo:', error);
      alert('Could not add todo. Is the backend running?');
    }
  };

  const toggleTodo = async (id: string) => {
    try {
      const response = await axios.put(`${API_URL}/todos/${id}`);
      setTodos(todos.map(todo => 
        todo.id === id ? response.data.todo : todo
      ));
    } catch (error) {
      console.error('Failed to toggle todo:', error);
    }
  };

  const deleteTodo = async (id: string) => {
    try {
      await axios.delete(`${API_URL}/todos/${id}`);
      setTodos(todos.filter(todo => todo.id !== id));
    } catch (error) {
      console.error('Failed to delete todo:', error);
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 to-purple-50 py-8">
      <div className="max-w-md mx-auto bg-white rounded-xl shadow-lg p-6">
        
        {/* Connection Status */}
        <div className={`mb-4 p-3 rounded-lg text-center ${
          connected ? 'bg-green-100 text-green-800' : 'bg-red-100 text-red-800'
        }`}>
          {connected ? '✅ Connected to Backend!' : '❌ Backend Disconnected'}
        </div>

        <h1 className="text-3xl font-bold text-center text-gray-800 mb-8">
          ✨  To-Do List
        </h1>

        {/* Add new todo */}
        <div className="flex gap-2 mb-6">
          <input
            type="text"
            value={newTodo}
            onChange={(e) => setNewTodo(e.target.value)}
            onKeyPress={(e) => e.key === 'Enter' && addTodo()}
            placeholder="What do you want to do?"
            className="flex-1 px-4 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-blue-500"
          />
          <button
            onClick={addTodo}
            className="bg-blue-500 text-white px-6 py-2 rounded-lg hover:bg-blue-600 transition-colors font-medium"
          >
            Add ✨
          </button>
        </div>

        {/* Loading */}
        {loading && (
          <div className="text-center py-4">
            <div className="animate-spin rounded-full h-8 w-8 border-b-2 border-blue-500 mx-auto"></div>
            <p className="mt-2 text-gray-600">Loading your todos...</p>
          </div>
        )}

        {/* Todos list */}
        <div className="space-y-3">
          {todos.length === 0 && !loading ? (
            <div className="text-center py-8 text-gray-500">
              <p className="text-lg">🎉 No todos yet!</p>
              <p>Add your first task above</p>
            </div>
          ) : (
            todos.map((todo) => (
              <div
                key={todo.id}
                className={`flex items-center gap-3 p-3 rounded-lg border ${
                  todo.completed 
                    ? 'bg-green-50 border-green-200' 
                    : 'bg-gray-50 border-gray-200'
                }`}
              >
                <input
                  type="checkbox"
                  checked={todo.completed}
                  onChange={() => toggleTodo(todo.id)}
                  className="w-5 h-5 text-blue-600 rounded focus:ring-blue-500"
                />
                <span
                  className={`flex-1 ${
                    todo.completed 
                      ? 'line-through text-gray-500' 
                      : 'text-gray-800'
                  }`}
                >
                  {todo.text}
                </span>
                <button
                  onClick={() => deleteTodo(todo.id)}
                  className="text-red-500 hover:text-red-700 font-medium"
                >
                  🗑️
                </button>
              </div>
            ))
          )}
        </div>

        {/* Stats */}
        <div className="mt-6 text-center text-sm text-gray-600">
          Total: {todos.length} | 
          Completed: {todos.filter(t => t.completed).length} | 
          Remaining: {todos.filter(t => !t.completed).length}
        </div>
      </div>
    </div>
  );
}

export default App;
