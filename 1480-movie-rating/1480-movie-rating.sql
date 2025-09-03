# Write your MySQL query statement below
WITH highest_user AS (
    SELECT u.name
    FROM Users u
    JOIN MovieRating r
      ON u.user_id = r.user_id
    GROUP BY u.user_id
    ORDER BY COUNT(r.movie_id) DESC, u.name ASC
    LIMIT 1
),
highest_movie AS (
    SELECT m.title
    FROM Movies m
    JOIN MovieRating r
      ON m.movie_id = r.movie_id
    WHERE r.created_at BETWEEN '2020-02-01' AND '2020-02-28'
    GROUP BY m.movie_id
    ORDER BY AVG(r.rating) DESC, m.title ASC
    LIMIT 1
)
SELECT name AS results FROM highest_user
UNION ALL
SELECT title AS results FROM highest_movie;
