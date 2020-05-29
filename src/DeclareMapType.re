/*
  This code illustrates an example of how to declare a map type in Reason ML.
  Reference: https://github.com/glennsl/bucklescript-cookbook#create-a-map-data-structure-add-or-replace-an-entry-and-print-each-keyvalue-pair

  Author: Mrinal Aswin
 */

/*
  What is Map type?
  > The map type represents a collection of elements where each element is stored as a key-value pair.
 */

/*
 Example using the standard library map.

 The API reference document for Map can be found here:
 https://reasonml.github.io/api/Map.Make.html

 It is a module functor which you must use to construct a
 map module for your specific key type.

 Using Map is immutable and is any key type.
 */

module StringMap =
  Map.Make({
    type t = string;
    let compare = compare;
  });

let indexMap =
  StringMap.(
    empty
    |> add("one", 1)
    |> add("two", 2)
    |> add("three", 3)
    |> add("four", 4)
    |> add("five", 5)
  );

indexMap |> StringMap.iter((k, v) => Js.log({j|key:$k, value: $v|j}));

/*
 Example using Js.Dict.

 The API reference document for the Js.Dict can be found here:
 https://bucklescript.github.io/bucklescript/api/Js.Dict.html

 Using Js.Dict is mutable and string key typed. It is supported only in buckleScript
 */

let indexMap =
  Js.Dict.fromList([("one", 1), ("two", 2), ("three", 3), ("four", 4)]);

let () = indexMap->Js.Dict.set("five", 5);

let () =
  indexMap
  |> Js.Dict.entries
  |> Js.Array.forEach(((k, v)) => Js.log({j|key:$k, value: $v|j}));

/*
 Example using an associative list.
 The API reference document for the List can be found here:
 https://reasonml.github.io/api/List.html

 Using associative list is immutable, any key type.
 */

let indexMap = [("one", 1), ("two", 2), ("three", 3), ("four", 4)];

let addOrReplace = ((k, v), l) => {
  let l' = l |> List.remove_assoc(k);
  [(k, v), ...l'];
};

indexMap
|> addOrReplace(("five", 5))
|> List.iter(((k, v)) => Js.log({j|key:$k, value: $v|j}));

/*
  Example using Hashtbl.
  The API reference document for the hashtbl can be found here:
  https://reasonml.github.io/api/Hashtbl.html

  Using Hashtbl is mutable and string key typed.

 */

let indexMap = Hashtbl.create(10);

let () = {
  indexMap->Hashtbl.add("one", 1);
  indexMap->Hashtbl.add("two", 2);
  indexMap->Hashtbl.add("three", 3);
  indexMap->Hashtbl.add("four", 4);
};

let () = indexMap->Hashtbl.replace("five", 5);

let () = indexMap |> Hashtbl.iter((k, v) => Js.log({j|key:$k, val:$v|j}));