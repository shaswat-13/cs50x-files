-- displays all the people starring in toy story
SELECT people.name
FROM people
JOIN stars ON people.id = stars.person_id
WHERE movie_id = (
    SELECT id
    FROM movies
    WHERE title = 'Toy Story'
);

