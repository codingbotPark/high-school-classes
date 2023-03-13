// import Main from "./components/main/Main";
import MainPage from "./pages/MainPage";
import NotFound from "./common/notFound/NotFound";
import WritePage from "./pages/WritePage"
import ReadPage from "./pages/ReadPage"
import EditPage from "./pages/EditPage";
import Profile from "./pages/ProfilePage";

const routes = [
    {path: '', element:<MainPage/>, header:true, footer:true},
    {path: '*', element:<NotFound/>, header:true,footer:true },
    {path: '/write', element:<WritePage/>, header:true, footer:true},
    {path:'/edit/:id',element:<EditPage/>, header:true,footer:true},
    {path: '/read/:id', element:<ReadPage/>, header:true,footer:true },
    {path: '/profile/:id', element:<Profile/>, header:true,footer:true }
]

export default routes