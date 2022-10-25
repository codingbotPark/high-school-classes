import Main from "./components/main/Main";
import NotFound from "./common/notFound/NotFound";

export default [
    {path: '', element:<Main/>, nav:true, footer:true},
    {path: '*', element:<NotFound/>, nav:true,footer:true }
]