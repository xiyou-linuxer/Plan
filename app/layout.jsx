import { Footer, Layout, Navbar } from 'nextra-theme-docs'
import { Banner, Head } from 'nextra/components'
import { getPageMap } from 'nextra/page-map'
import 'nextra-theme-docs/style.css'
import './assets/style.css'

export const metadata = {
  // Define your metadata here
  // For more information on metadata API, see: https://nextjs.org/docs/app/building-your-application/optimizing/metadata
}

const head = (
  <link rel="icon" href="https://www.xiyoulinux.com/favicon.ico"></link>
)
const navbar = (
  <Navbar
    align="left"
    logo={<strong className="type-song">培养计划</strong>}
    projectLink="https://github.com/xiyou-linuxer/Plan"
    chatLink="https://www.xiyoulinux.com/"
    chatIcon={<img src="https://www.xiyoulinux.com/favicon.ico" width="24" />}
  />
)
const footer = <Footer>© {new Date().getFullYear()} 西邮 Linux 兴趣小组</Footer>

export default async function RootLayout({ children }) {
  return (
    <html lang="zh" dir="ltr" suppressHydrationWarning>
      <Head children={head} />
      <body>
        <Layout
          // banner={banner}
          navbar={navbar}
          pageMap={await getPageMap()}
          docsRepositoryBase="https://github.com/xiyou-linuxer/Plan"
          footer={footer}
          feedback={{ content: '向本页提出Issue' }}
          editLink="编辑本页"
          themeSwitch={{
            dark: '深色模式',
            light: '浅色模式',
            system: '自动',
          }}
          toc={{
            title: '目录',
            backToTop: '回到顶部',
          }}
        >
          {children}
        </Layout>
      </body>
    </html>
  )
}
