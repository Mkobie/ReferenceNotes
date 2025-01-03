## Checklist
Concepts to double-check before submitting code, based on common mistakes:
- DRY: what is repeated?
- YAGNI: what isn't being used (yet)?
- Open/closed: when someone adds to this, will they modify existing code?
- Is stuff decoupled? are different concepts/responsibilities mixed together in classes/methods?
- Are concerns separated? what might cause this component to change? if >1 reasons, then poor separation of concerns.
- Composition over inheritance: "has a" where possible; use "is a" only when want to reuse functionality across derived classes, and there’s a clear hierarchical relationship.
- Interfaces over implementation: describe "what it does" (behaviour) not "how it does it" (implementation)
- Runtime flexibility: able to change in main fn?
- DI: are dependencies visible/test-friendly (constructor), temp/short-lived (method), or optional/cyclic (setter)
- OOP: sensible reflection of real world concepts?

## Strategy pattern
For encapsulating families of "stuff" separately and having them swappable at runtime without altering client code.

![](assets/strategy_pattern.JPG)
Image from Head First Design Patterns

Use if you need:
- Different actions in different circumstances
  - Example: Sorting algorithms (e.g., bubble sort, quicksort, merge sort) that can be applied dynamically.
- To deal with class behaviour that'll change frequently
  - Example: A payment system that can switch between PayPal, credit card, and cryptocurrency processing.
- Behaviour flexibility at runtime
  - Example: A video game character that can switch between "melee attack," "magic attack," or "stealth mode" based on player input.
- To get rid of excessive conditionals
  - Example: A UI element that changes its rendering behavior (e.g., for dark mode, light mode, high contrast mode).
- Separation of concerns
  - Example: A pricing calculator that applies different discount strategies (e.g., seasonal discount, member discount).

Don't use if:
- Will generate excessive boilerplate code
- Don't need dynamic behaviour, or couple conditionals can do it for you
- context class (the one using the strategy) gets complex
- Need to optimize performance
- Will have coupling between client and strategy classes
