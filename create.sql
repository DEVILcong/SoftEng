USE test;
CREATE TABLE building
(
    builbNo CHAR(1) PRIMARY KEY,
    roomNum SMALLINT,
    floorNum SMALLINT,
    chargeStd FLOAT,
    manageNo CHAR(2)
);

CREATE TABLE room
(
    roomNo CHAR(5) PRIMARY KEY,
    roomSize SMALLINT,
    roomOwner CHAR(8)
);

CREATE TABLE people
(
    roomNo CHAR(5) PRIMARY KEY,
    peopleId CHAR(18),
    name CHAR(8),
    sex CHAR(6) CHECK(sex='man'or sex='woman'),
    phone CHAR(12),
    familyNum SMALLINT,
    FOREIGN KEY (roomNo) REFERENCES room(roomNo)
);

CREATE TABLE worker
(
    workId CHAR(2) PRIMARY KEY,
    name CHAR(8),
    sex CHAR(5) CHECK(sex='man' or sex='woman'),
    phone CHAR(12),
    ID CHAR(18) UNIQUE
);

CREATE TABLE charge
(
    roomNo CHAR(5) PRIMARY KEY,
    lastdate CHAR(8),
    price FLOAT,
    ifHand char(1),
    debt FLOAT,
    FOREIGN KEY (roomNo) REFERENCES room(roomNo)
);

CREATE TABLE questions
(
    quesNo CHAR(4) PRIMARY KEY,
    roomNo CHAR(5),
    whenHappen CHAR(8),
    quesDesc CHAR(60),
    howSolve CHAR(40),
    manager CHAR(2),
    FOREIGN KEY (roomNo) REFERENCES room(roomNo),
    FOREIGN KEY (manager) REFERENCES worker(workId)
) 
