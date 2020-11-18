#!/usr/bin/node
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/';
const request = require('request');
request(url, function (err, response, body) {
  if (err) { console.log(err); }
  const val = JSON.parse(body).characters;
  charprint(val, 0);
});

function charprint (strwars, s) {
  request(strwars[s], function (err, response, body) {
    if (err) { console.log(err); }
    console.log(JSON.parse(body).name);
    if (s + 1 < strwars.length) {
      charprint(strwars, s + 1);
    }
  });
}
