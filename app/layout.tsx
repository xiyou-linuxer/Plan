import { Footer, Layout, Navbar } from "nextra-theme-docs";
import { Head, Search } from "nextra/components";
import { getPageMap } from "nextra/page-map";
import Logo from "./components/Logo";

import "nextra-theme-docs/style.css";
import "./global.css";

const title = "西邮 Linux 兴趣小组培养计划";
const projectLink = "https://github.com/xiyou-linuxer/Plan";

export const metadata = {
  // https://nextjs.org/docs/app/building-your-application/optimizing/metadata
  // https://github.com/shuding/nextra/blob/main/docs/app/layout.tsx
  metadataBase: new URL("https://plan.xiyoulinux.com/"),
  generator: "Next.js",
  applicationName: title,
  appleWebApp: { title },
  title: {
    default: title,
    template: `%s | ${title}`,
  },
  openGraph: {
    // https://github.com/vercel/next.js/discussions/50189#discussioncomment-10826632
    url: "./",
    siteName: title,
    locale: "zh",
    type: "website",
  },
  alternates: {
    // https://github.com/vercel/next.js/discussions/50189#discussioncomment-10826632
    canonical: "./",
  },
};

const navbar = (
  <Navbar
    logo={<Logo />}
    projectLink={projectLink}
    chatLink="https://www.xiyoulinux.com/"
    chatIcon={
      <img
        className="w-6"
        src="https://www.xiyoulinux.com/favicon.ico"
        title="西邮 Linux 兴趣小组主站"
      />
    }
  />
);

const search = (
  <Search
    emptyResult="未找到结果"
    loading="正在搜索…"
    errorText="搜索失败"
    placeholder="请善用搜索功能"
  />
);

const footer = (
  <Footer className="flex-wrap gap-x-6 gap-y-2">
    <span>© {new Date().getFullYear()} 西邮 Linux 兴趣小组</span>
    <a
      href="https://beian.miit.gov.cn"
      target="_blank"
      rel="noopener noreferrer nofollow"
    >
      陕ICP备2023007680号-1
    </a>
  </Footer>
);

export default async function RootLayout({ children }) {
  const pageMap = await getPageMap();

  return (
    <html lang="zh" dir="ltr">
      <Head />
      <body>
        <Layout
          navbar={navbar}
          search={search}
          docsRepositoryBase={projectLink}
          pageMap={pageMap}
          themeSwitch={{
            dark: "深色模式",
            light: "浅色模式",
            system: "自动",
          }}
          toc={{
            title: "目录",
            backToTop: "回到顶部",
          }}
          feedback={{ content: null }}
          editLink={null}
          footer={footer}
        >
          {children}
        </Layout>
      </body>
    </html>
  );
}
