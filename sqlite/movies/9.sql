-- displays a person only once
SELECT DISTINCT people.name
FROM people
WHERE id IN (

    -- selecting persons id
    SELECT stars.person_id
    FROM stars
    WHERE stars.movie_id IN (

        -- movies released in the year 2004
        SELECT movies.id
        FROM movies
        WHERE movies.year = 2004
    )
)
ORDER BY birth ASC;
