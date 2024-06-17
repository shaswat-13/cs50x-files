
-- names of the people with the id
SELECT people.name
FROM people
WHERE people.id IN (

    -- id of all the people who starred in the movie
    SELECT stars.person_id
    FROM stars
    WHERE stars.movie_id IN (

        -- all movies id in which kevin bacon starred in
        SELECT stars.movie_id
        FROM stars
        WHERE stars.person_id IN (

            -- kevin bacon born in 1958's id
            SELECT people.id
            FROM people
            WHERE people.name = 'Kevin Bacon'
            AND birth = 1958
            )
    )
)
-- removing Kevin Bacon from the list
AND people.name != 'Kevin Bacon';

