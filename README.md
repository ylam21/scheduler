# scheduler
Scheduler is a tool for generating work schedules based on employee availability and work limits.

## Worker Assignment Algorithm
![User Assignment Algorithm](./images/algorithm.jpg)

## Installation
Clone the repository:
```
git clone git@github.com:ylam21/scheduler.git scheduler
```
```
cd scheduler
```
## Configuration
Set employee names, their availability and limits in:
```
scheduler/config/users.c
```
Availability Values:
- 0 = Not available
- 1 = Available
- 2 = Available with priority

Work Limits:
- index 0 = Minimum workdays
- index 1 = Maximum workdays
- index 2 = Exact number of workdays
- value '-1' = No restriction

Set the maximum consecutive workdays in:
```
scheduler/include/user.h
```
## Usage
Compile and run:
```
make && ./bin
```
