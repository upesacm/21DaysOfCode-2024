-- Task 1
-- Retrieve the names of employees and their corresponding department names
SELECT e.employee_name, d.dept_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id;

-- Task 2
-- Calculate the total number of employees in each department
SELECT d.dept_name, COUNT(e.employee_id) AS total_employees
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id
GROUP BY d.dept_name;

-- Task 3
-- Retrieve the names of employees who have a salary greater than the average salary of the employees in their department
SELECT e.employee_name
FROM employees e
WHERE e.salary > (
    SELECT AVG(e2.salary)
    FROM employees e2
    WHERE e2.dept_id = e.dept_id
);

-- Task 4
-- Delete all employees who belong to the 'Marketing' department from the employees table
DELETE FROM employees
WHERE dept_id = (SELECT dept_id FROM departments WHERE dept_name = 'Marketing');
