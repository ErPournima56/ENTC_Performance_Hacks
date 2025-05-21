## 📘 Optimization Technique: Precompute Constants
When working on embedded systems, precomputing constants is a simple yet powerful way to reduce runtime computation and save valuable CPU cycles.

## 🧠 What is it?
Instead of calculating a value repeatedly during program execution, compute it once (at compile time or startup), and reuse the result

## 🚀 Why it's useful in embedded systems
✅ Faster execution – no need to repeat calculations.
✅ Lower power consumption – fewer instructions = less energy.
✅ Smaller code paths – great for interrupt routines or real-time loops.

📍 Where to use this
- Inside real-time loops or interrupts
- When working with fixed math constants
- In code that gets called frequently or has tight timing constraints

Preconpute Constants
