import React from 'react';
import { useState } from 'react';
import { useEffect } from 'react';
import * as R from "./ReadmeParser.style"

// 스타일은 각자
const ReadmeParser = ({content}) => {

    const [result,setResult] = useState();

    let counter = 1;

    function processFrontCommand(splitedLine){
        splitedLine.shift();
        return splitedLine.join(" ")
    }

    function unitContentParser(line){
        const splitedLine = line.split(" ");
        switch(splitedLine[0]){ // 라인의 첫 번째
            case "#":
                // splitedLine.shift();
                return <R.H1 key={counter++}>{processFrontCommand(splitedLine)}</R.H1>
            case "##":
                return <R.H2 key={counter++}>{processFrontCommand(splitedLine)}</R.H2>
            case "###":
                return <R.H3 key={counter++}>{processFrontCommand(splitedLine)}</R.H3>
            case ">":
                return <R.Q key={counter++}>{processFrontCommand(splitedLine)}</R.Q>
            default:
                return <R.P key={counter++}>{line}</R.P>
        }
    }

    useEffect(() => {
        if (content){
            setResult(content.split("\n").map((i) => unitContentParser(i)));
        }
    },[content])

    return (
        <>
            {
                result

                // content.split("\n").map((i, idx) => unitContentParser(i))
                

                // content.split("\n").map((i, idx) => {
                //     //enter로 한 번 나눈다
                //     const splitedLine = i.split(" ");
                //     console.log(splitedLine);
                    
                //     switch (
                //       splitedLine[0] // 라인을 스페이스바로 나눴을 때 첫 명령
                //     ) {
                //       case "#":
                //         // 명령어 라인 삭제
                //         // console.log(splitedLine)
                //         splitedLine.shift();
                //         return <h1 key={idx}>{splitedLine}</h1>;
                //       case "##":
  
                //       default: // 첫 줄에 명령어가 없을 때(bold, a 파악)
                //         return <p key={idx}></p>;
                //     }
                //   })
                
                // content.split("\n").map((i, idx) => (

                // ))

                
            } 
        </>
    );
};

export default ReadmeParser;