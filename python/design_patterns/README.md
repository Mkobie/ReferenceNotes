## Checklist
Things to double-check before submitting code, based on common mistakes:

Concepts ("what" we're aiming for):
- DRY: what is repeated?
- YAGNI: what isn't being used (yet)?
- SRP: what might cause this component to change? if >1 reasons, then the responsibility isn't single, is it.
- Open/closed: when someone adds to this, will they modify existing code?
- Is stuff decoupled? are different concepts/responsibilities mixed together in classes/methods?
- Runtime flexibility: able to change in main fn?
- OOP: sensible reflection of real world concepts?

Principles ("how" we'll achieve it)
- Composition over inheritance: "has a" where possible (composition); use "is a" (inheritance) only when want to reuse ALL base class functionality across derived classes (and won't want to change it, eg at runtime), and there’s a clear hierarchical relationship.
  - Supports runtime flexibility & separation of concerns
  - Note: base class is considered "fragile" if it's going to need changes that'll require changes in all its inheriting classes.
- Interfaces over implementation: describe "what it does" (behaviour) not "how it does it" (implementation)
  - Supports decoupling and open/closed principle
- DI: are dependencies visible/test-friendly (constructor), temp/short-lived (method), or optional/cyclic (setter)
  - Supports decoupling and testability
- Are things that vary separated from what stays the same?

## Strategy pattern
For encapsulating families of "stuff" separately and having them swappable at runtime without altering client code.

![](assets/strategy_pattern.JPG)
Image from Head First Design Patterns

Use if you need:
- Clear open/closed format
- Nice separation of concerns
  - In particular: things that vary to be separate from things that stay the same
- Loose coupling: remaining coupling (client implementation of strategy) is explicit (if constructor DI is used)
- Runtime flexibility
- Reusability
- To avoid excessive if-else conditionals

Don't use if:
- You don't like how much boilerplate code it generates
- You don't need dynamic behaviour, or couple conditionals can do it for you
- Your context class (the one using the strategy) gets complex
- You need to optimize performance
- You can't live with the level of coupling it creates between client and strategy classes
