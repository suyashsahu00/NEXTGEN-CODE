import { z } from 'zod';


const FormSchema = z.object({
  name: z.string().min(2, "Name must be at least 2 characters!"),
  email: z.string().email("Please enter a valid email!"),
  age: z.number().min(1, "Age must be a positive number!")
});


type FormData = z.infer<typeof FormSchema>;

export { FormSchema, type FormData };
