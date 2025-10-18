import { useForm, Controller,FieldErrors  } from 'react-hook-form';
import { zodResolver } from '@hookform/resolvers/zod';
import { z } from 'zod';

// Zod Schema - Form validation rules
const FormSchema = z.object({
  name: z.string().min(2, "Name must be at least 2 characters!"),
  email: z.string().email("Please enter a valid email!"),
  age: z.number().min(1, "Age must be a positive number!")
});

// TypeScript type from Zod schema
type FormData = z.infer<typeof FormSchema>;

export default function MyForm() {
  const { 
    control,           // Controller for inputs
    handleSubmit,      // Form submission handler
    formState: { errors, isSubmitting },  // Form state and errors
    reset              // Function to reset form
  } = useForm<FormData>({
    resolver: zodResolver(FormSchema),  // Connect Zod validation
    defaultValues: {    // Default values
      name: "",
      email: "",
      age: 18
    }
  });

  // Updated onSubmit function with backend connection
  const onSubmit = async (data: FormData) => {
    try {
      console.log("🚀 Sending data to backend:", data);
      
      // Send data to backend API
      const response = await fetch('http://localhost:5000/api/submit-form', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(data)
      });
      
      // Parse response from backend
      const result = await response.json();
      
      if (response.ok) {
        // Success! Show success message
        alert(`✅ ${result.message}`);
        console.log("✅ Success:", result);
        reset(); // Clear the form after successful submission
      } else {
        // Error from backend
        alert(`❌ Error: ${result.message}`);
        console.error("❌ Backend error:", result);
      }
    } catch (error) {
      // Network or other error
      console.error("❌ Network error:", error);
      alert("🔥 Failed to submit form. Please check if backend is running!");
    }
  };

  // Function that runs when form has validation errors
const onError = (errors: FieldErrors<FormData>) => {
  console.log("📝 Form validation errors:", errors);
};

  return (
    <div className="max-w-md mx-auto mt-8 p-6 bg-white rounded-lg shadow-md">
      <h2 className="text-2xl font-bold mb-6 text-center text-blue-600">
        🎯 My Form
      </h2>
      
      <form onSubmit={handleSubmit(onSubmit, onError)} className="space-y-4">
        
        {/* Name Input Field */}
        <Controller
          name="name"
          control={control}
          render={({ field }) => (
            <div>
              <label className="block text-sm font-medium mb-1 text-gray-700">
                👤 Name:
              </label>
              <input
                {...field}
                type="text"
                placeholder="Enter your name"
                disabled={isSubmitting}  // Disable during submission
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 disabled:bg-gray-100"
              />
              {errors.name && (
                <p className="text-red-500 text-sm mt-1">
                  ❌ {errors.name.message}
                </p>
              )}
            </div>
          )}
        />

        {/* Email Input Field */}
        <Controller
          name="email"
          control={control}
          render={({ field }) => (
            <div>
              <label className="block text-sm font-medium mb-1 text-gray-700">
                📧 Email:
              </label>
              <input
                {...field}
                type="email"
                placeholder="your.email@example.com"
                disabled={isSubmitting}  // Disable during submission
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 disabled:bg-gray-100"
              />
              {errors.email && (
                <p className="text-red-500 text-sm mt-1">
                  ❌ {errors.email.message}
                </p>
              )}
            </div>
          )}
        />

        {/* Age Input Field */}
        <Controller
          name="age"
          control={control}
          render={({ field }) => (
            <div>
              <label className="block text-sm font-medium mb-1 text-gray-700">
                🎂 Age:
              </label>
              <input
                {...field}
                type="number"
                placeholder="Enter your age"
                disabled={isSubmitting}  // Disable during submission
                onChange={(e) => field.onChange(Number(e.target.value))}
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:outline-none focus:ring-2 focus:ring-blue-500 disabled:bg-gray-100"
              />
              {errors.age && (
                <p className="text-red-500 text-sm mt-1">
                  ❌ {errors.age.message}
                </p>
              )}
            </div>
          )}
        />

        {/* Submit Button */}
        <button 
          type="submit"
          disabled={isSubmitting}  // Disable during submission
          className={`w-full py-2 px-4 rounded-md transition-colors duration-200 text-white font-medium ${
            isSubmitting 
              ? 'bg-gray-400 cursor-not-allowed' 
              : 'bg-blue-500 hover:bg-blue-600'
          }`}
        >
          {isSubmitting ? (
            <span className="flex items-center justify-center">
              ⏳ Submitting...
            </span>
          ) : (
            <span>🚀 Submit Form</span>
          )}
        </button>
      </form>
    </div>
  );
}
