use test_schema;

CREATE TABLE class (
    CIsNO char (6) PRIMARY KEY,
    CLslame varchar(16) NOT NULL, Director varchar(10) , Specialty varchar(30) ,
    stotal int NULL,
    monitor varchar (50) NULL
    );

CREATE TABLE student (
    Sno char(8) PRIMARY KEY,    -- 学号（主键）
    Sname varchar(10)NOT NULL,  -- 姓名
    Ssex char(2) CHECK (Ssex='女' OR Ssex='男'),    -- 性别
    CIsNO char(6),  -- 班级编号
    Saddr varchar(20),  -- 住址
    Sage numeric (3, 0) CHECK ( (Sage >(10) AND Sage< (30) )),  -- 年龄
    Height decimal (4,2),   -- 身高
    Sdept varchar (30)  -- 院系
);

ALTER TABLE student 
WITH CHECK ADD CHECK ((Sage>(10) AND Sage<(30)));

ALTER TABLE student 
WITH CHECK ADD CHECK ((Ssex='女' AND Ssex='男'));
