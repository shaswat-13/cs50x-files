-- displays the movies starring Jennifer Lawrence and Bradley Cooper
SELECT movies.title
FROM movies
WHERE movies.id IN (

    -- selects all the movies of Jennifer Lawrence
    SELECT stars.movie_id
    FROM stars
    WHERE stars.person_id = (

        -- selects id of Jennifer Lawrence
        SELECT people.id
        FROM people
        WHERE name = 'Jennifer Lawrence'
        )
)

AND movies.id IN (

    -- selects all the movies of bradley cooper
    SELECT stars.movie_id
    FROM stars
    WHERE stars.person_id = (

        -- selects id of Bradley Cooper
        SELECT people.id
        FROM people
        WHERE name = 'Bradley Cooper'
        )
);
