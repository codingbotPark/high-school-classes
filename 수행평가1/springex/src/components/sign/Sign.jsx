import React,{createContext} from 'react';
import { useState } from 'react';
import SignUp from "./signUp/SignUp"
import SignIn from "./signIn/SignIn"

export const ModeSetterContext = createContext();
export const ModalSetterContext = createContext();

const Sign = ({setModalIsOpen}) => {

    const [mode,setMode] = useState("signIn");

    return (
        <ModalSetterContext.Provider value={setModalIsOpen}>
       <ModeSetterContext.Provider value={setMode}>
       {
        mode === "signUp" ? 
        <SignUp/>:
        <SignIn/>
       }
       </ModeSetterContext.Provider>
       </ModalSetterContext.Provider>
       
    );
};

export default Sign;