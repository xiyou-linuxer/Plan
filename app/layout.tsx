import { Footer, Layout, Navbar } from 'nextra-theme-docs'
import { Head } from 'nextra/components'
import { getPageMap } from 'nextra/page-map'
import 'nextra-theme-docs/style.css'
import './global.css'

export const metadata = {
  // https://nextjs.org/docs/app/building-your-application/optimizing/metadata
}

const faviconUrl = 'https://www.xiyoulinux.com/favicon.ico'

const head = <link rel="icon" href={faviconUrl} />

const navbarLogo = <strong className="type-song">培养计划</strong>
const projectLink = 'https://github.com/xiyou-linuxer/Plan'
const chatLink = 'https://www.xiyoulinux.com/'
const chatIcon = <img src={faviconUrl} width="24" alt="主站" />

const navbar = (
  <Navbar
    align="left"
    logo={navbarLogo}
    projectLink={projectLink}
    chatLink={chatLink}
    chatIcon={chatIcon}
  />
)

const footer = <Footer>© {new Date().getFullYear()} 西邮 Linux 兴趣小组</Footer>

const themeSwitchOptions = {
  dark: '深色模式',
  light: '浅色模式',
  system: '自动',
}

const tocOptions = {
  title: '目录',
  backToTop: '回到顶部',
}

export default async function RootLayout({ children }) {
  const pageMap = await getPageMap()
  return (
    <html lang="zh" dir="ltr" suppressHydrationWarning>
      <Head>{head}</Head>
      <body>
        <Layout
          navbar={navbar}
          pageMap={pageMap}
          docsRepositoryBase={projectLink}
          footer={footer}
          feedback={{ content: '向本页提出Issue' }}
          editLink="编辑本页"
          themeSwitch={themeSwitchOptions}
          toc={tocOptions}
        >
          {children}
        </Layout>
      </body>
    </html>
  )
}
