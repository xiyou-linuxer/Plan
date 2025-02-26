import { Footer, Layout, Navbar } from 'nextra-theme-docs'
import { Head } from 'nextra/components'
import { getPageMap } from 'nextra/page-map'
import 'nextra-theme-docs/style.css'
import './global.css'

const title = '西邮 Linux 兴趣小组培养计划'

export const metadata = {
  // https://nextjs.org/docs/app/building-your-application/optimizing/metadata
  // https://github.com/shuding/nextra/blob/main/docs/app/layout.tsx
  metadataBase: new URL('https://plan.xiyoulinux.com/'),
  generator: 'Next.js',
  applicationName: title,
  appleWebApp: { title },
  title: {
    default: title,
    template: `%s | ${title}`,
  },
  openGraph: {
    url: './',
    siteName: title,
    locale: 'zh',
    type: 'website',
  },
  alternates: {
    // https://github.com/vercel/next.js/discussions/50189#discussioncomment-10826632
    canonical: './',
  },
}

const head = <></>

const projectLink = 'https://github.com/xiyou-linuxer/Plan'

const navbar = (
  <Navbar
    align="left"
    logo={<span className="type-song">培养计划</span>}
    projectLink={projectLink}
    chatLink="https://www.xiyoulinux.com/"
    chatIcon={<span>主站</span>}
  />
)

const footer = (
  <Footer className="gap-4">
    <span>© {new Date().getFullYear()} 西邮 Linux 兴趣小组</span>
    <a href="https://beian.miit.gov.cn" target="_blank" rel="noopener noreferrer nofollow">陕ICP备2023007680号-1</a>
  </Footer>
)

export default async function RootLayout({ children }) {
  const pageMap = await getPageMap()
  return (
    <html lang="zh" dir="ltr" suppressHydrationWarning>
      <Head>{head}</Head>
      <body>
        <Layout
          navbar={navbar}
          docsRepositoryBase={projectLink}
          pageMap={pageMap}
          themeSwitch={{
            dark: '深色模式',
            light: '浅色模式',
            system: '自动',
          }}
          toc={{
            title: '目录',
            backToTop: '回到顶部',
          }}
          feedback={{
            content: '提出Issue',
          }}
          editLink="编辑本页"
          footer={footer}
        >
          {children}
        </Layout>
      </body>
    </html>
  )
}
