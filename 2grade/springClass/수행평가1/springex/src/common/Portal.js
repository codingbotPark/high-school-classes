import { createPortal } from "react-dom";

function Portal({ children, elementId }) {
  const rootElement = document.getElementById(elementId)
  return createPortal(children,rootElement)
}

export default Portal