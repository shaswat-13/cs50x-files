-- Displays all the movies and their ratings released in 2010 in descending order of the ratings
-- if the ratings of any two movies are same then  displays them in ascending alphabetical order
SELECT movies.title, ratings.rating
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010
AND ratings.rating IS NOT NULL
ORDER BY ratings.rating DESC, movies.title ASC;
