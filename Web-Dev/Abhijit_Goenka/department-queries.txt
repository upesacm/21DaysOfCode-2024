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

INSERT INTO departments (dept_id,dept_name)
SELECT 4, 'New Department'
WHERE NOT EXISTS (SELECT 1 FROM departments WHERE dept_id = 4);

SELECT d.dept_id,SUM(e.salary) AS total
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id
GROUP BY d.dept_name;

UPDATE employees
SET salary = salary*1.05
WHERE dept_id = (SELECT dept_id FROM departments WHERE dept_name= 'Engineering');

DROP TABLE employees;

DROP DATABASE ACM21DOC;



