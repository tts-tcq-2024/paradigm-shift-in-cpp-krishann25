# paradigm-shift-cplus
# Programming Paradigms

Electric Vehicles have BMS - Battery Management Systems

[Here is an article that helps to understand the need for BMS](https://circuitdigest.com/article/battery-management-system-bms-for-electric-vehicles)

[Wikipedia gives an idea of the types and topologies](https://en.wikipedia.org/wiki/Battery_management_system)

[This site gives the optimum Charging-temperature limits](https://batteryuniversity.com/learn/article/charging_at_high_and_low_temperatures)

[This abstract suggests a range for the optimum State of Charge](https://www.sciencedirect.com/science/article/pii/S2352484719310911)

[Here is a reference for the maximum charge rate](https://www.electronics-notes.com/articles/electronic_components/battery-technology/li-ion-lithium-ion-charging.php#:~:text=Constant%20current%20charge:%20In%20the%20first%20stage%20of,rate%20of%20a%20maximum%20of%200.8C%20is%20recommended.)

## Possible purpose

- Protect batteries while charging:
at home, in public place, within vehicle / regenerative braking
- Estimate life, inventory and supply chains

## The Starting Point

We will explore the charging phase of Li-ion batteries to start with.

## Issues

- The code here has high complexity in a single function.
- The tests are not complete - they do not cover all the needs of a consumer

## Tasks

1. Reduce the cyclomatic complexity.
1. Separate pure functions from I/O
1. Avoid duplication - functions that do nearly the same thing
1. Complete the tests - cover all conditions.
1. To take effective action, we need to know
the abnormal measure and the breach -
whether high or low. Add this capability.

## The Exploration

How well does our code hold-out in the rapidly evolving EV space?
Can we add new functionality without disturbing the old?

## The Landscape

- Limits may change based on new research
- Technology changes due to obsolescence
- Sensors may be from different vendors with different accuracy
- Predicting the future requires Astrology!

## Keep it Simple

Shorten the Semantic distance

- Procedural to express sequence
- Functional to express relation between input and output
- Object oriented to encapsulate state with actions
- Apect oriented to capture repeating aspects

Extending and Refactoring

This exercise is about extending functionality. Work on the repository from your previous assignment to extend it (see extensions below). Often, code becomes more complex while extending it. The 'cleanliness' of the code goes down.

The skill of refactoring keeps the code clean and fresh.

This assignment is a continuation in the Paradigm Shift.
Extensions

Try at least One of these extensions on your code. Mention the extensions you select in your README.md file.
Extension 1: Early Warning

Customers need early warnings to take action, in addition to the alarm that you print after the limit is breached. Introduce a 'warning' level with a tolerance of 5% of the upper-limit.

Example: If the SoC needs to be between 20 and 80, the warning-tolerance is 5% of 80 = 4. Warnings need to be displayed in these ranges:

    20 to 20+4 Warning: Approaching discharge
    80-4 to 80 Warning: Approaching charge-peak

Same for Temperature and Charge-rate.

Keep in mind: Though we are starting with warning levels for all parameters, customers may give feedback to have warnings only for some parameters and not others. Minimize the change needed for such 'tuning'.
Extension 2: Support a language in addition to English

Our market has expanded to German-speaking countries! Switch the language of the printed messages based on a global variable.

Use Google translate if you aren't familiar with German.

Keep in mind: We could add more languages in future. Minimize the code-change required.
The starting point

Write a failing test. The asserts will specify the data-design (inputs and outputs). Imagine a consumer and ensure that the asserts reflect the consumer's need.

Experience the places where test / code gets more complex. Think of refactoring opportunities.
Recommended Approach

Treat the problem as a series of data-transformations. A chain of transformations is suggested below.

    Translate to common units

    Map the breach to the ranges. Keep the code common across parameters and vary the data.

    Example: Design a data-structure with a series of numbers representing the boundary of each condition. In the example above:
        0 to 20: LOW_SOC_BREACH
        21 to 24: LOW_SOC_WARNING
        24 to 75: NORMAL
        76 to 80: HIGH_SOC_WARNING
        81 to 100: HIGH_SOC_BREACH

    Translate the anomaly to a message in the appropriate language

    Output the resulting message

    Compute overall Battery status. Make logical assumptions in case of warning and error combinations.

Each transformation is one function (or more). Do not mix different transformations in the same function. Have one function to chain ('compose') these transformation-functions.
