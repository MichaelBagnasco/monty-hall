# Monty Hall Problem Simulation

This program simulates the Monty Hall problem to demonstrate the probabilities of winning for different strategies. The
simulation includes three players:

- Player 1: Never switches their initial choice.
- Player 2: Always switches their initial choice.
- Player 3: Switches their choice randomly 50% of the time.

The program runs the simulation for a specified number of plays and outputs the results, including the time taken to
complete the simulation.

## Explanation

The odds of winning for keeping the door is ~33.3%. The odds for switching is the inverse, ~66.6%.

| Behind Door 1 | Behind Door 2 | Behind Door 3 | Result if staying at door #1 | Result if switching to the door offered |
|---------------|---------------|---------------|------------------------------|-----------------------------------------|
| Goat          | Goat          | Car           | Wins Goat                    | **Wins Car**                            |
| Goat          | Car           | Goat          | Wins Goat                    | **Wins Car**                            |
| Car           | Goat          | Goat          | **Wins Car**                 | Wins Goat                               |

## Example Output

```
Results after 100000 rounds:
keep wins: 33229
keep win rate: 0.33229
switch wins: 66771
switch win rate: 0.66771
Random (50%) switch wins: 49736
Random (50%) switch win rate: 0.49736
```