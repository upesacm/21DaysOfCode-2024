CREATE TABLE employees (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_name VARCHAR(100) NOT NULL,
    salary DECIMAL(10, 2) NOT NULL,
    dept_id INT NOT NULL
);

INSERT INTO employees (emp_name, salary, dept_id) VALUES
('Alice Johnson', 60000.00, 1),
('Bob Smith', 55000.00, 2),
('Charlie Brown', 70000.00, 1),
('Diana Lee', 65000.00, 3),
('Eve Wang', 58000.00, 2);

CREATE TABLE departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(100) NOT NULL
);

INSERT INTO departments (dept_id, dept_name) VALUES
(1, 'Engineering'),
(2, 'Marketing'),
(3, 'Finance');

SELECT * FROM employees;
SELECT * FROM departments;

SELECT employees.emp_name AS employee_name,departments.dept_name AS department_name 
FROM employees
JOIN departments ON employees.dept_id=departments.dept_id;

SELECT departments.dept_name AS department_name , count(employees.emp_id) AS total_emply
FROM employees
JOIN departments ON employees.dept_id=departments.dept_id
GROUP BY department_name;

SELECT e1.emp_name AS employee_name, e1.salary, d.dept_name AS department_name
FROM employees e1
JOIN departments d ON e1.dept_id = d.dept_id
WHERE e1.salary > (
    SELECT AVG(e2.salary)
    FROM employees e2
    WHERE e2.dept_id = e1.dept_id
);


DELETE FROM employees
WHERE dept_id = (
    SELECT dept_id
    FROM departments
    WHERE dept_name = 'Marketing'
);



