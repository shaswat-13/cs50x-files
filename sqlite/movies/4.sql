-- counts the number of movies which has the rating of 10.0
SELECT count(*)
FROM movies
WHERE movies.id = (

    -- movie id with rating 10
    SELECT ratings.movie_id
    FROM ratings
    WHERE rating = 10
);
