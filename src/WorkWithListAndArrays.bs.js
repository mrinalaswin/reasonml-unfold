// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

var a = /* :: */[
  1,
  /* :: */[
    2,
    /* :: */[
      3,
      /* [] */0
    ]
  ]
];

var b = /* :: */[
  0,
  a
];

List.iter((function (i) {
        console.log("" + (String(i) + ""));
        
      }), a);

List.iter((function (i) {
        console.log("" + (String(i) + ""));
        
      }), b);

var c = Pervasives.$at(a, /* :: */[
      4,
      /* [] */0
    ]);

List.iter((function (i) {
        console.log("" + (String(i) + ""));
        
      }), c);

var d = [
  1,
  2,
  3
];

$$Array.iter((function (i) {
        console.log("" + (String(i) + ""));
        
      }), d);

Caml_array.caml_array_set(d, 0, 2);

$$Array.iter((function (i) {
        console.log("" + (String(i) + ""));
        
      }), d);

console.log($$Array.of_list(a));

console.log($$Array.to_list(d));

exports.a = a;
exports.b = b;
exports.c = c;
exports.d = d;
/*  Not a pure module */