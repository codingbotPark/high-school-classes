import React,{createContext} from 'react';
import { useState } from 'react';
import SignUp from "./signUp/SignUp"
import SignIn from "./signIn/SignIn"

export const ModeSetterContext = createContext();

const Sign = () => {

    const [mode,setMode] = useState("signIn");

    return (
       <ModeSetterContext.Provider value={setMode}>
       {
        mode === "signUp" ? 
        <SignUp/>:
        <SignIn/>
       }
       </ModeSetterContext.Provider>
       
    );
};

export default Sign;