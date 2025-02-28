import { NotFoundPage } from "nextra-theme-docs";
import Logo from "./components/Logo";

export default function NotFound() {
  return (
    <NotFoundPage content="提交 issue" labels="broken-link">
      <h1 className="relative">
        <Logo className="text-6xl opacity-5 lg:text-9xl" />
        <span className="absolute top-1/2 left-1/2 -translate-1/2 text-2xl">
          页面未找到
        </span>
      </h1>
    </NotFoundPage>
  );
}
