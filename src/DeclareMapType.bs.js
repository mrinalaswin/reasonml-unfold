// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Map = require("bs-platform/lib/js/map.js");
var List = require("bs-platform/lib/js/list.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Hashtbl = require("bs-platform/lib/js/hashtbl.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");

var compare = Caml_obj.caml_compare;

var StringMap = $$Map.Make({
      compare: compare
    });

var indexMap = Curry._3(StringMap.add, "five", 5, Curry._3(StringMap.add, "four", 4, Curry._3(StringMap.add, "three", 3, Curry._3(StringMap.add, "two", 2, Curry._3(StringMap.add, "one", 1, StringMap.empty)))));

Curry._2(StringMap.iter, (function (k, v) {
        console.log("key:" + (String(k) + (", value: " + (String(v) + ""))));
        
      }), indexMap);

var indexMap$1 = Js_dict.fromList(/* :: */[
      /* tuple */[
        "one",
        1
      ],
      /* :: */[
        /* tuple */[
          "two",
          2
        ],
        /* :: */[
          /* tuple */[
            "three",
            3
          ],
          /* :: */[
            /* tuple */[
              "four",
              4
            ],
            /* [] */0
          ]
        ]
      ]
    ]);

indexMap$1["five"] = 5;

Js_dict.entries(indexMap$1).forEach((function (param) {
        console.log("key:" + (String(param[0]) + (", value: " + (String(param[1]) + ""))));
        
      }));

function addOrReplace(param, l) {
  var k = param[0];
  var l$prime = List.remove_assoc(k, l);
  return /* :: */[
          /* tuple */[
            k,
            param[1]
          ],
          l$prime
        ];
}

List.iter((function (param) {
        console.log("key:" + (String(param[0]) + (", value: " + (String(param[1]) + ""))));
        
      }), addOrReplace(/* tuple */[
          "five",
          5
        ], /* :: */[
          /* tuple */[
            "one",
            1
          ],
          /* :: */[
            /* tuple */[
              "two",
              2
            ],
            /* :: */[
              /* tuple */[
                "three",
                3
              ],
              /* :: */[
                /* tuple */[
                  "four",
                  4
                ],
                /* [] */0
              ]
            ]
          ]
        ]));

var indexMap$2 = Hashtbl.create(undefined, 10);

Hashtbl.add(indexMap$2, "one", 1);

Hashtbl.add(indexMap$2, "two", 2);

Hashtbl.add(indexMap$2, "three", 3);

Hashtbl.add(indexMap$2, "four", 4);

Hashtbl.replace(indexMap$2, "five", 5);

Hashtbl.iter((function (k, v) {
        console.log("key:" + (String(k) + (", val:" + (String(v) + ""))));
        
      }), indexMap$2);

exports.StringMap = StringMap;
exports.addOrReplace = addOrReplace;
exports.indexMap = indexMap$2;
/* StringMap Not a pure module */
