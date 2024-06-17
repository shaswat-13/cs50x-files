-- displays the 5 highest rated movies starred by chadwick boseman
SELECT movies.title
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.id IN (

    -- selects the movies_id that chadwick boseman starred in
    SELECT stars.movie_id
    FROM stars
    WHERE stars.person_id IN (

        -- selects the id of chadwick boseman
        SELECT people.id
        FROM people
        WHERE name = 'Chadwick Boseman'

    )
)
ORDER BY ratings.rating DESC
LIMIT 5;
