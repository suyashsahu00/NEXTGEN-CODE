import { useForm, Controller, FieldErrors } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";
import { z } from "zod";

// Validation schema with Zod
const RegistrationSchema = z.object({
  username: z.string().min(3, "Username must be at least 3 characters!"),
  email: z.string().email("Please enter a valid email address!"),
  password: z.string().min(6, "Password must be at least 6 characters!"),
});

type RegistrationData = z.infer<typeof RegistrationSchema>;

export default function RegistrationForm() {
  const {
    control,
    handleSubmit,
    formState: { errors, isSubmitting },
    reset,
  } = useForm<RegistrationData>({
    resolver: zodResolver(RegistrationSchema),
    defaultValues: {
      username: "",
      email: "",
      password: "",
    },
  });

  const onSubmit = async (data: RegistrationData) => {
    try {
      const response = await fetch("http://localhost:5000/api/register", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data),
      });

      const result = await response.json();

      if (response.ok) {
        alert(`✅ ${result.message}`);
        reset();
      } else {
        alert(`❌ Error: ${result.message}`);
      }
    } catch {
      alert("🔥 Registration failed! Check backend connection!");
    }
  };

  return (
    <div className="max-w-md mx-auto mt-8 p-6 bg-white rounded-lg shadow-md">
      <h2 className="text-2xl font-bold mb-6 text-center text-green-600">
        🔐 User Registration
      </h2>
      <form onSubmit={handleSubmit(onSubmit)} className="space-y-4">
        <Controller
          name="username"
          control={control}
          render={({ field }) => (
            <div>
              <label className="block text-sm font-medium mb-1 text-gray-700">
                👤 Username:
              </label>
              <input
                {...field}
                type="text"
                placeholder="Your Username"
                disabled={isSubmitting}
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:ring-2 focus:ring-green-500"
              />
              {errors.username && (
                <p className="text-red-500 text-sm mt-1">{errors.username.message}</p>
              )}
            </div>
          )}
        />

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
                placeholder="your@email.com"
                disabled={isSubmitting}
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:ring-2 focus:ring-green-500"
              />
              {errors.email && (
                <p className="text-red-500 text-sm mt-1">{errors.email.message}</p>
              )}
            </div>
          )}
        />

        <Controller
          name="password"
          control={control}
          render={({ field }) => (
            <div>
              <label className="block text-sm font-medium mb-1 text-gray-700">
                🔒 Password:
              </label>
              <input
                {...field}
                type="password"
                placeholder="Choose a password"
                disabled={isSubmitting}
                className="w-full px-3 py-2 border border-gray-300 rounded-md focus:ring-2 focus:ring-green-500"
              />
              {errors.password && (
                <p className="text-red-500 text-sm mt-1">{errors.password.message}</p>
              )}
            </div>
          )}
        />

        <button
          type="submit"
          disabled={isSubmitting}
          className={`w-full py-2 px-4 rounded-md text-white font-medium ${
            isSubmitting
              ? "bg-gray-400 cursor-not-allowed"
              : "bg-green-500 hover:bg-green-600"
          }`}
        >
          {isSubmitting ? "⏳ Registering..." : "🚀 Register Account"}
        </button>
      </form>
      <div className="mt-4 text-center text-sm text-gray-600">
        💾 <strong>Note:</strong> Your password is encrypted and never shared!
      </div>
    </div>
  );
}
