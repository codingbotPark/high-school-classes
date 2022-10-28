import React from 'react';

const ReadmeParser = ({content}) => {

    // function unitContentParser(line){

    // }

    return (
        <>
            {
                content.split("\n").map((i, idx) => {
                    
                })
                

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