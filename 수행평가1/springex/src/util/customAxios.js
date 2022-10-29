import axios, { AxiosError } from "axios";
import config from "../config/config.json"

const customAxios = axios.create({
    baseURL: config.server,
    timeout: 1000
});

customAxios.interceptors.request.use(
    function (config) {
        // const accessToken = localStorage.getItem("access_token");
        // if (accessToken) {
        //     config.headers = {
        //         Authorization: `Bearer ${accessToken}`,
        //     }
        // }
        return config;
    },
    function (error) {
        return Promise.reject(error);
    }
);

export default customAxios