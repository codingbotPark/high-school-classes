import * as A from "./App.style"

import { Route, Routes, useLocation } from 'react-router-dom'
import { useLayoutEffect, useState } from 'react'

import routes from "./routes"


function App() {
  const location = useLocation();
  const [renderInfo]

  return (
    <A.Core>
      <Routes>
        {
          routes.map(element => {
            return <Route
              path={element.path}
              element={element.element}
              key={element.path}
            />
          })
        }
      </Routes>
    </A.Core>
  );
}

export default App;
