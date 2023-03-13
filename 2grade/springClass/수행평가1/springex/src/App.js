import * as A from "./App.style";

import { Route, Routes, useLocation } from "react-router-dom";
import { useLayoutEffect, useState } from "react";

import Header from "./common/header/Header";
import Footer from "./common/footer/Footer";

import routes from "./routes";

// global-style
import { ThemeProvider } from "styled-components";
import { GlobalStyle } from "./styles/global";
import { darkTheme, lightTheme } from "./styles/theme";


function App() {
  const location = useLocation();
  const [renderInfo, setRenderInfo] = useState({
    header: true,
    footer: true,
  });

  useLayoutEffect(() => {
    let temp = routes.find(
      (element) => element.path === location.pathname.split("/")[1]
    );
    if (temp === undefined) {
      temp = routes.find((element) => element.path === "*");
    }
    setRenderInfo({ header: temp.header, footer: temp.footer });
  }, [location.pathname]);

  return (
    <ThemeProvider theme={lightTheme}>
      <GlobalStyle />
      <A.Wrapper>
      {renderInfo.header && <Header/>}
      <A.Core>
        <Routes>
          {routes.map((element) => {
            return (
              <Route
                path={element.path}
                element={element.element}
                key={element.path}
              />
            );
          })}
        </Routes>
      </A.Core>
      {renderInfo.footer && <Footer/>}
      </A.Wrapper>
    </ThemeProvider>
  );
}

export default App;
