SELECT name FROM people
    JOIN stars ON stars.person_id = people.id
    WHERE stars.movie_id IN (
        SELECT movie_id FROM stars
        WHERE person_id = (
            SELECT id FROM people
            WHERE name = 'Kevin Bacon' AND birth = '1958'))
            EXCEPT
            SELECT name FROM people
            WHERE name = 'Kevin Bacon' AND birth = '1958';

