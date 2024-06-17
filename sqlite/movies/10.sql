-- displays the name of directors only once
SELECT DISTINCT people.name
FROM people
WHERE people.id IN (

    -- selects the id of directors who directed those movies
    SELECT directors.person_id
    FROM directors
    WHERE directors.movie_id IN (

        -- selects all the movies with rating at least 9.0
        SELECT ratings.movie_id
        FROM ratings
        WHERE ratings.rating >= 9.0
    )
);
