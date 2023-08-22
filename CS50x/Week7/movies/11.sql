SELECT title
FROM ratings
    JOIN movies ON movies.id = ratings.movie_id
    WHERE movies.id IN (
        SELECT id FROM movies
            JOIN stars ON stars.movie_id = movies.id
            WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
            ORDER BY rating DESC LIMIT 5;


