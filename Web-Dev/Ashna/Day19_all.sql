-- Exercise 1
-- Insert a new department 'Human Resources' if it does not already exist
INSERT INTO departments (dept_id, dept_name)
SELECT 4, 'Human Resources'
WHERE NOT EXISTS (SELECT 1 FROM departments WHERE dept_id = 4);

-- Exercise 2
-- Calculate the total salary expenses for each department
SELECT d.dept_name, SUM(e.salary) AS total_salary_expenses
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id
GROUP BY d.dept_name;

-- Exercise 3
-- Update the salary of employees in the 'Engineering' department by increasing it by 5%
UPDATE employees
SET salary = salary * 1.05
WHERE dept_id = (SELECT dept_id FROM departments WHERE dept_name = 'Engineering');

-- Exercise 4
-- Drop the 'employees' table
DROP TABLE employees;

-- Exercise 5
-- Drop the database 'ACM21DOC'
DROP DATABASE ACM21DOC;
