// import Main from "./components/main/Main";
import MainPage from "./pages/MainPage";
import NotFound from "./common/notFound/NotFound";
import WritePage from "./pages/WritePage"
import ReadPage from "./pages/ReadPage"

export default [
    {path: '', element:<MainPage/>, header:true, footer:true},
    {path: '*', element:<NotFound/>, header:true,footer:true },
    {path: '/write', element:<WritePage/>, header:true, footer:true},
    {path: '/read/:id', element:<ReadPage/>, header:true,footer:true }
]