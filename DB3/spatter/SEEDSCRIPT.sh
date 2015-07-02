#!/bin/bash

#Reset database
rake db:reset

## ADD USERS 
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/users -d '{"user": {"email":"test1@foo.com", "name":"Jim", "password":"fooasdasdasd"}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/users -d '{"user": {"email":"test2@foo.com", "name":"Bob", "password":"basdasdasdar"}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/users -d '{"user": {"email":"test3@foo.com", "name":"Joe", "password":"foasdasdasdo"}}'

# MAKE USER 1 FOLLOW USERS 2 AND 3 
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/users/follows -d '{"id":1, "follows_id":2}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/users/follows -d '{"id":1, "follows_id":3}'

## CREATE SPATTS
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":3}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":2}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":1}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":2}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":3}}'

curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":2}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":1}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":1}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":3}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":2}}'

curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":1}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":2}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":3}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":1}}'
curl -i -H "Content-type: application/json" -X POST http://glenn.sqrawler.com:3000/spatts -d '{"spatt": {"body":"Hello, Splatter world", "user_id":3}}'

## FIRST USERS SPATTS
curl -i -H "Content-type: application/json" -X GET   http://glenn.sqrawler.com:3000/users/spatts/1

## FIRST USERS NEWS FEED
curl -i -H "Content-type: application/json" -X GET   http://glenn.sqrawler.com:3000/users/spatts-feed/1

## FIRST USER TO UNFOLLOW THIRD
 curl -i -H "Content-type: application/json" -X DELETE http://glenn.sqrawler.com:3000/users/follows/1/3
 
 ## FIRST USERS NEWS FEED AFTER UNFOLLOW
curl -i -H "Content-type: application/json" -X GET   http://glenn.sqrawler.com:3000/users/spatts-feed/1