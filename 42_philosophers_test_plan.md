
# 42 Philosophers Project - Test Plan

## 1. Basic Functionality Tests
These tests ensure the program behaves correctly under normal conditions.

| **#** | `n_philosophers` | `time_to_die` (ms) | `time_to_eat` (ms) | `time_to_sleep` (ms) | `number_of_meals` | **Expected Result** |
|-------|------------------|--------------------|---------------------|----------------------|-------------------|---------------------|
| 1     | 5                | 800                | 200                 | 200                  | -                 | Philosophers alternate eating, sleeping, and thinking without starving. |
| 2     | 4                | 1000               | 300                 | 300                  | 10                | Simulation ends after 10 meals per philosopher. No one dies. |

---

## 2. Edge Case Tests
These tests evaluate how the program handles extreme or unusual conditions.

| **#** | `n_philosophers` | `time_to_die` (ms) | `time_to_eat` (ms) | `time_to_sleep` (ms) | `number_of_meals` | **Expected Result** |
|-------|------------------|--------------------|---------------------|----------------------|-------------------|---------------------|
| 3     | 1                | 500                | 200                 | 200                  | -                 | The single philosopher alternates between eating and sleeping, no starvation. |
| 4     | 0                | 800                | 200                 | 200                  | -                 | Program exits with an error or does nothing, as no philosophers are present. |
| 5     | 5                | 100                | 50                  | 50                   | -                 | Philosophers may starve if forks are not picked up fast enough. |
| 6     | 5                | 300                | 200                 | 200                  | -                 | At least one philosopher will die due to starvation. |

---

## 3. Stress Tests
These tests push the program to its limits to test performance and resource handling.

| **#** | `n_philosophers` | `time_to_die` (ms) | `time_to_eat` (ms) | `time_to_sleep` (ms) | `number_of_meals` | **Expected Result** |
|-------|------------------|--------------------|---------------------|----------------------|-------------------|---------------------|
| 7     | 200              | 1000               | 100                 | 100                  | -                 | All philosophers alternate eating and sleeping; no starvation, high CPU usage. |
| 8     | 100              | 500                | 200                 | 200                  | 20                | Program completes without crashing; no philosopher starves. |
| 9     | 5                | 1000               | 4000                | 4000                 | -                 | Slow simulation with visible delays in eating and sleeping. No starvation. |

---

## 4. Invalid Input Tests
These tests verify how well the program handles incorrect or invalid inputs.

| **#** | Input Arguments                          | **Expected Result**                           |
|-------|------------------------------------------|-----------------------------------------------|
| 10    | `5 -200 100 100`                        | Program exits with an error about negative `time_to_die`. |
| 11    | `five 800 200 200`                      | Program exits with an error about invalid input type. |
| 12    | `5 800 200`                             | Program exits with an error about missing arguments. |
| 13    | `5 800 200 200 0`                       | Program exits immediately since `number_of_meals` is zero. |

---

## 5. Scalability Tests
Evaluate how well the program handles increasing complexity.

| **#** | `n_philosophers` | `time_to_die` (ms) | `time_to_eat` (ms) | `time_to_sleep` (ms) | `number_of_meals` | **Expected Result** |
|-------|------------------|--------------------|---------------------|----------------------|-------------------|---------------------|
| 14    | 10               | 800                | 200                 | 200                  | 50                | Simulation completes without crashes. |
| 15    | 1000             | 5000               | 500                 | 500                  | -                 | High resource usage; test for system stability. |

---

## Execution Steps
1. **Run each test case** using the appropriate arguments. For example:
   ```bash
   ./philosophers 5 800 200 200
   ```
2. **Observe program behavior**, particularly:
   - Correctness: Do all philosophers follow the expected eating/sleeping/thinking pattern?
   - Termination: Does the program end cleanly for finite meal cases?
   - Errors: Does the program handle invalid input gracefully?
   - Starvation: Do all philosophers eventually eat, or do some die unnecessarily?

3. **Monitor resource usage** during stress tests:
   - Use tools like `htop` or `top` to monitor CPU and memory.
   - Check if the program can manage large numbers of threads efficiently.

4. **Log outputs and compare them** to expected results. Use debugging tools or add custom logs to trace thread activity if necessary.
