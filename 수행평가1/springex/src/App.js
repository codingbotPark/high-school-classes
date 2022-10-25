import * as A from "./App.style";

import { Route, Routes, useLocation } from "react-router-dom";
import { useLayoutEffect, useState } from "react";

import routes from "./routes";

import { ThemeProvider } from "styled-components"; // 커스텀한 css컴포넌트 임포트해오기
import { GlobalStyle } from "./styles/global";
import { darkTheme, lightTheme } from "./styles/theme";

function App() {
  const location = useLocation();
  const [renderInfo, setRenderInfo] = useState({
    nav: true,
    footer: true,
  });

  useLayoutEffect(() => {
    let temp = routes.find(
      (element) => element.path === location.pathname.split("/")[1]
    );
    if (temp === undefined) {
      temp = routes.find((element) => element.path === "*");
    }
    setRenderInfo({ nav: temp.nav, footer: temp.footer });
  }, [location.pathname]);

  return (
    <ThemeProvider theme={lightTheme}>
      <GlobalStyle />
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
    </ThemeProvider>
  );
}

export default App;
