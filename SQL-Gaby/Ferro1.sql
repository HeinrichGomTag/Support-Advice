-- Escriba una consulta para seleccionar el nombre de todos los profesores del departamento de History.
select name from instructor where dept_name = 'History';

-- Obtenga la cantidad de empleados “masculinos” en la base de datos employees. Muestre el resultado nombrando la columna como “Hombres”.
-- Select all male employees and count them
SELECT count(*) FROM employees WHERE gender = "masculino"

-- Encuentre la inscripción de cada sección que se ofreció en la primavera (spring) de 2009.
SELECT * FROM employees WHERE 

-- Encuentre en la base de datos university el profesor que gana el salario más bajo.
-- Select the professor with the lowest salary
    SELECT * FROM instructor WHERE salary = (SELECT MIN(salary) FROM instructor)

-- Encuentre en la base de datos university el nombre y el departamento al que pertenece del estudiante con la mayor cantidad de créditos.
-- Select the name and department of the student with the most credits
    SELECT name, dept_name FROM student WHERE tot_cred = (SELECT MAX(tot_cred) FROM student)

-- Encuentre en la base de datos university la capacidad de cada salón de clases, eliminando cualquier repetición.
-- Select the capacity of each classroom, removing any duplicates
    SELECT DISTINCT capacity FROM classroom

-- Encuentre en la base de datos university el nombre de los profesores que NO asesoran a estudiantes.
-- Select the names of the professors that do not advise students
    SELECT name FROM instructor WHERE ID NOT IN (SELECT ID FROM advisor)

-- Encuentre la inscripción de cada sección que se ofreció en la primavera (spring) de 2009.
-- Select the enrollment of each section that was offered in the spring of 2009
    SELECT * FROM section WHERE semester = "Spring" AND year = 2009

-- Encuentre en la base de datos university el nombre de los estudiantes asesorados por el profesor Katz.
-- Select the names of the students advised by professor Katz
    SELECT name FROM student WHERE ID IN (SELECT ID FROM advisor WHERE ID = (SELECT ID FROM instructor WHERE name = "Katz"))

-- Encuentre en la base de datos employees el nombre y apellido de los empleados que han sido jefes de departamento y el salario promedio que han tenido en la compañía.
-- Select the name and last name of the employees that have been department managers and the average salary they have had in the company
    -- Salaries is other table with salary
    SELECT first_name, last_name FROM employees WHERE emp_no IN (SELECT emp_no FROM dept_manager) GROUP BY first_name, last_name
    -- Show average salary 
    SELECT AVG(salary) FROM salaries WHERE emp_no IN (SELECT emp_no FROM dept_manager)
    