CREATE TABLE student (
    id INTEGER NOT NULL,
    student_name TEXT NOT NULL,
    house_id INTEGER NOT NULL,
    FOREIGN KEY(house_id) REFERENCES houses(id)
    PRIMARY KEY(id)
);

CREATE TABLE houses (
    id INTEGER NOT NULL,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE student_house_assignments (
    id INTEGER NOT NULL,
    house_id INTEGER NOT NULL,
    student_id INTEGER NOT NULL,
    PRIMARY KEY(id)
);




notes:
# i don't watch harry potter.
house / head names:

Slytherin - Severus Snape
Ravenclaw - Filius Flitwick
Hufflepuff - Pomona Sprout
Gryffindor - Minerva McGonagalle