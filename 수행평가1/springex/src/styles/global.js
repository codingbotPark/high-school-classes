import { createGlobalStyle } from 'styled-components'

export const GlobalStyle = createGlobalStyle`
      * {
        box-sizing: border-box;
        color:${(props) => props.theme.fontColor};
        transition:0.2s;
      }
      html{
        height:100%;
      }
      div{
        background-color:${(props) => props.theme.background};
        
      }
      #__next{
        background-color:${(props) => props.theme.htmlBackground};
      }
      body{
        font-family: -apple-system,system-ui,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,sans-serif;
      }
      a {
        color: inherit;
        text-decoration: none;
      }
      input, button {
        background-color: transparent;
        border: none;
        outline: none;
      }
      h1, h2, h3, h4, h5, h6{
        font-family:'Maven Pro', sans-serif;
        color:${(props) => props.theme.fontColor};
      }
      p{
        color:${(props) => props.theme.fontColor}
      }

      @media only screen and (max-width: 768px) {
        body {
          font-size: 12px;
        }
      }

      @media only screen and (max-width: 576px) {
        body {
          font-size: 10px;
        }
      }
    `
