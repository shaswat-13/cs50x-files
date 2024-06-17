-- displaying all the songs of post malone
SELECT name
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = 'Post Malone'
);
