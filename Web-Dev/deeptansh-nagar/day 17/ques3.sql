CREATE TABLE STUDENTS (
  Name VARCHAR(15) NOT NULL,
  Bdate DATE,
  Sex CHAR
);

INSERT INTO STUDENTS (Name, Bdate, Sex)
VALUES ('John Doe', '2001-01-01', 'M');

INSERT INTO STUDENTS (Name, Bdate, Sex)
VALUES ('Jane Smith', '2002-02-02', 'F');

INSERT INTO STUDENTS (Name, Bdate, Sex)
VALUES ('Bob Johnson', '2003-03-03', 'M');

INSERT INTO STUDENTS (Name, Bdate, Sex)
VALUES ('Alice Brown', '2004-04-04', 'F');

SELECT * FROM STUDENTS;
