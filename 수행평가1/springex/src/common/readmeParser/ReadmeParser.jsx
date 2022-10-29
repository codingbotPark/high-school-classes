import React from "react";
import { useState } from "react";
import { useEffect } from "react";
import * as R from "./ReadmeParser.style";

// 스타일은 각자
const ReadmeParser = ({ content }) => {
  const [result, setResult] = useState();

  let counter = 1;

  function processFrontCommand(splitedLine) {
    splitedLine.shift();
    return splitedLine.join(" ");
  }

  // function unitContentParser(unit){
  //     // console.log(unit.replace(/\!\[([^\]]+)\]\(([^\)]+)\)/, <img src="$2" alt="$1" />));
  //     const parser = new DOMParser();
  //     const replaced = unit.replace(/\!\[([^\]]+)\]\(([^\)]+)\)/, '<img src="$2" alt="$1" />')
  //     const parsed = parser.parseFromString(replaced,'text/html');
  //     console.log(parsed.body.childNodes[0])
  //     return parsed.body.childNodes[0]

  // }

  function lineContentParser(line) {
    const splitedLine = line.split(" ");
    switch (
      splitedLine[0] // 라인의 첫 번째
    ) {
      case "#":
        // splitedLine.shift();
        return <R.H1 key={counter++}>{processFrontCommand(splitedLine)}</R.H1>;
      case "##":
        return <R.H2 key={counter++}>{processFrontCommand(splitedLine)}</R.H2>;
      case "###":
        return <R.H3 key={counter++}>{processFrontCommand(splitedLine)}</R.H3>;
      case ">":
        return <R.Q key={counter++}>{processFrontCommand(splitedLine)}</R.Q>;
      default:
        // return splitedLine.map((unit) => {
        //     unitContentParser(unit)
        // })
        return <R.P key={counter++}>{line}</R.P>;
    }
  }

  useEffect(() => {
    setResult(content.split("\n").map((i) => lineContentParser(i)));
  }, [content]);

  return (
    <R.Wrapper>
      {
        result
      }
    </R.Wrapper>
  );
};

export default ReadmeParser;
